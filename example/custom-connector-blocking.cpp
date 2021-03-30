#include <banana/api.hpp>
#include <banana/utils/connector.hpp>

#include <iostream>
#include <sstream>
#include <fstream>

/// Stupid but working custom connector example
class basic_dumb_connector {
    std::string m_token;

public:
    explicit basic_dumb_connector(std::string token) : m_token(std::move(token)) {
        // nothing
    }

    /// Our connector is stupid so it will use `curl` utility to make requests
    banana::expected<std::string> do_request(std::string_view method, std::optional<std::string> body) {
        // Temporarily files
        const std::string temp_input  = "./input.tmp";
        const std::string temp_output = "./output.tmp";

        // Dump request body to file
        {
            std::ofstream tg_json(temp_input);
            tg_json << body.value_or("");
        }

        // Prepare curl command that printing output to our temp file
        std::stringstream curl_command;
        curl_command << "curl -X POST ";
        curl_command << "-H 'Content-Type: application/json' ";
        curl_command << "-s ";
        curl_command << "-d '@" << temp_input << "' ";
        curl_command << "-o " << temp_output << " ";
        curl_command << "https://api.telegram.org/bot" << m_token << "/" << method;

        auto result = [&]() -> banana::expected<std::string> {
            // Try run `curl`
            if (std::system(curl_command.str().c_str()) != 0) {
                // On failure, return some error
                return banana::error_t<>{ "unknown error" };
            }

            // On success, read temp file and return its content as a result
            std::ifstream tg_answer(temp_output);
            return banana::expected(std::string{ std::istreambuf_iterator<char>(tg_answer), {} });
        }();

        // Cleaning up
        std::remove(temp_input.c_str());
        std::remove(temp_output.c_str());

        return result;
    }
};

// Use helper traits to generate connector interface from `basic_dumb_connector`
using dumb_connector_monadic = banana::connector::make_blocking<basic_dumb_connector>;
using dumb_connector = banana::connector::make_throwing<dumb_connector_monadic>;

static_assert(std::is_same_v<
    banana::api_result<banana::api::message_t, dumb_connector_monadic>,
    banana::expected<banana::api::message_t>
>);

static_assert(std::is_same_v<
    banana::api_result<banana::api::message_t, dumb_connector>,
    banana::api::message_t
>);

int main(int argc, const char** argv) {
    if (argc < 3) {
        std::cout << "usage: " << (argc > 0 ? argv[0] : "./self") << " token target [name] [os]\n";
        return 2;
    }

    const std::string token  = argv[1];
    const std::string target = argv[2];
    const std::string name   = argc > 3 ? argv[3] : "<unknown>";
    const std::string os     = argc > 4 ? argv[4] : "<unknown>";

    const std::string message_text = "Hello from " + name + " at " + os + "!";

    try {
        dumb_connector connector(token);

        std::cout << "bot name: " << banana::api::get_me(connector).username.value() << "\n";
        std::cout << "message sent: " << banana::api::send_message(connector, { target, message_text + " (throwing)" }).message_id << "\n";
    }
    catch (std::exception& e) {
        std::cout << "exception while running throwing " << name << ": " << e.what() << "\n";
        return 1;
    }

    try {
        dumb_connector_monadic connector(token);

        std::cout << "bot name: " << banana::api::get_me(connector).value().username.value() << "\n";
        std::cout << "message sent: " << banana::api::send_message(connector, { target, message_text + " (monadic)" }).value().message_id << "\n";
    }
    catch (std::exception& e) {
        std::cout << "exception while running monadic " << name << ": " << e.what() << "\n";
        return 1;
    }
}
