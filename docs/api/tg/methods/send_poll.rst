.. _banana-api-tg-methods-send_poll:

send_poll
=========

.. cpp:namespace:: banana::api
.. cpp:function:: template <class Agent> \
                  api_result<message_t, Agent&&> send_poll(Agent&& agent, send_poll_args_t args)
.. cpp:function:: template <class Agent, class F> \
                  void send_poll(Agent&& agent, send_poll_args_t args, F&& callback)

   ``agent`` is any object satisfying :ref:`agent concept <banana-api-banana-agents>`.

   ``callback`` is any callable object accepting ``expected<message_t>``.

   Use this method to send a native poll. On success, the sent Message is returned.

.. cpp:struct:: send_poll_args_t

   Arguments that should be passed to :cpp:func:`send_poll`.


   .. cpp:member:: variant_t<integer_t, string_t> chat_id

   Unique identifier for the target chat or username of the target channel (in the format @channelusername)

   .. cpp:member:: optional_t<integer_t> message_thread_id

   Unique identifier for the target message thread (topic) of the forum; for forum supergroups only

   .. cpp:member:: string_t question

   Poll question, 1-300 characters

   .. cpp:member:: array_t<string_t> options

   A JSON-serialized list of answer options, 2-10 strings 1-100 characters each

   .. cpp:member:: optional_t<boolean_t> is_anonymous

   True, if the poll needs to be anonymous, defaults to True

   .. cpp:member:: optional_t<string_t> type

   Poll type, “quiz” or “regular”, defaults to “regular”

   .. cpp:member:: optional_t<boolean_t> allows_multiple_answers

   True, if the poll allows multiple answers, ignored for polls in quiz mode, defaults to False

   .. cpp:member:: optional_t<integer_t> correct_option_id

   0-based identifier of the correct answer option, required for polls in quiz mode

   .. cpp:member:: optional_t<string_t> explanation

   Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-200 characters with at most 2 line feeds after entities parsing

   .. cpp:member:: optional_t<string_t> explanation_parse_mode

   Mode for parsing entities in the explanation. See formatting options for more details.

   .. cpp:member:: optional_t<array_t<message_entity_t>> explanation_entities

   A JSON-serialized list of special entities that appear in the poll explanation, which can be specified instead of parse_mode

   .. cpp:member:: optional_t<integer_t> open_period

   Amount of time in seconds the poll will be active after creation, 5-600. Can't be used together with close_date.

   .. cpp:member:: optional_t<integer_t> close_date

   Point in time (Unix timestamp) when the poll will be automatically closed. Must be at least 5 and no more than 600 seconds in the future. Can't be used together with open_period.

   .. cpp:member:: optional_t<boolean_t> is_closed

   Pass True if the poll needs to be immediately closed. This can be useful for poll preview.

   .. cpp:member:: optional_t<boolean_t> disable_notification

   Sends the message silently. Users will receive a notification with no sound.

   .. cpp:member:: optional_t<boolean_t> protect_content

   Protects the contents of the sent message from forwarding and saving

   .. cpp:member:: optional_t<reply_parameters_t> reply_parameters

   Description of the message to reply to

   .. cpp:member:: optional_t<variant_t<inline_keyboard_markup_t, reply_keyboard_markup_t, reply_keyboard_remove_t, force_reply_t>> reply_markup

   Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
