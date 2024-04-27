/// Forward declarations
struct animation_t;
struct audio_t;
struct bot_command_scope_all_chat_administrators_t;
struct bot_command_scope_all_group_chats_t;
struct bot_command_scope_all_private_chats_t;
struct bot_command_scope_chat_administrators_t;
struct bot_command_scope_chat_member_t;
struct bot_command_scope_chat_t;
struct bot_command_scope_default_t;
struct bot_command_t;
struct callback_game_t;
struct callback_query_t;
struct chat_invite_link_t;
struct chat_location_t;
struct chat_member_administrator_t;
struct chat_member_banned_t;
struct chat_member_left_t;
struct chat_member_member_t;
struct chat_member_owner_t;
struct chat_member_restricted_t;
struct chat_member_updated_t;
struct chat_permissions_t;
struct chat_photo_t;
struct chat_t;
struct chosen_inline_result_t;
struct contact_t;
struct dice_t;
struct document_t;
struct encrypted_credentials_t;
struct encrypted_passport_element_t;
struct file_t;
struct force_reply_t;
struct game_high_score_t;
struct game_t;
struct inline_keyboard_button_t;
struct inline_keyboard_markup_t;
struct inline_query_result_article_t;
struct inline_query_result_audio_t;
struct inline_query_result_cached_audio_t;
struct inline_query_result_cached_document_t;
struct inline_query_result_cached_gif_t;
struct inline_query_result_cached_mpeg4_gif_t;
struct inline_query_result_cached_photo_t;
struct inline_query_result_cached_sticker_t;
struct inline_query_result_cached_video_t;
struct inline_query_result_cached_voice_t;
struct inline_query_result_contact_t;
struct inline_query_result_document_t;
struct inline_query_result_game_t;
struct inline_query_result_gif_t;
struct inline_query_result_location_t;
struct inline_query_result_mpeg4_gif_t;
struct inline_query_result_photo_t;
struct inline_query_result_venue_t;
struct inline_query_result_video_t;
struct inline_query_result_voice_t;
struct inline_query_t;
struct input_contact_message_content_t;
struct input_file_t;
struct input_invoice_message_content_t;
struct input_location_message_content_t;
struct input_media_animation_t;
struct input_media_audio_t;
struct input_media_document_t;
struct input_media_photo_t;
struct input_media_video_t;
struct input_text_message_content_t;
struct input_venue_message_content_t;
struct invoice_t;
struct keyboard_button_poll_type_t;
struct keyboard_button_t;
struct labeled_price_t;
struct location_t;
struct login_url_t;
struct mask_position_t;
struct message_auto_delete_timer_changed_t;
struct message_entity_t;
struct message_id_t;
struct message_t;
struct order_info_t;
struct passport_data_t;
struct passport_element_error_data_field_t;
struct passport_element_error_file_t;
struct passport_element_error_files_t;
struct passport_element_error_front_side_t;
struct passport_element_error_reverse_side_t;
struct passport_element_error_selfie_t;
struct passport_element_error_translation_file_t;
struct passport_element_error_translation_files_t;
struct passport_element_error_unspecified_t;
struct passport_file_t;
struct photo_size_t;
struct poll_answer_t;
struct poll_option_t;
struct poll_t;
struct pre_checkout_query_t;
struct proximity_alert_triggered_t;
struct reply_keyboard_markup_t;
struct reply_keyboard_remove_t;
struct response_parameters_t;
struct shipping_address_t;
struct shipping_option_t;
struct shipping_query_t;
struct sticker_set_t;
struct sticker_t;
struct successful_payment_t;
struct update_t;
struct user_profile_photos_t;
struct user_t;
struct venue_t;
struct video_note_t;
struct video_t;
struct voice_chat_ended_t;
struct voice_chat_participants_invited_t;
struct voice_chat_scheduled_t;
struct voice_chat_started_t;
struct voice_t;
struct webhook_info_t;

/// Type aliases

// This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:
using bot_command_scope_t = variant_t<bot_command_scope_default_t, bot_command_scope_all_private_chats_t, bot_command_scope_all_group_chats_t, bot_command_scope_all_chat_administrators_t, bot_command_scope_chat_t, bot_command_scope_chat_administrators_t, bot_command_scope_chat_member_t>;

// This object contains information about one member of a chat. Currently, the following 6 types of chat members are supported:
using chat_member_t = variant_t<chat_member_owner_t, chat_member_administrator_t, chat_member_member_t, chat_member_restricted_t, chat_member_left_t, chat_member_banned_t>;

// This object represents one result of an inline query. Telegram clients currently support results of the following 20 types:
using inline_query_result_t = variant_t<inline_query_result_cached_audio_t, inline_query_result_cached_document_t, inline_query_result_cached_gif_t, inline_query_result_cached_mpeg4_gif_t, inline_query_result_cached_photo_t, inline_query_result_cached_sticker_t, inline_query_result_cached_video_t, inline_query_result_cached_voice_t, inline_query_result_article_t, inline_query_result_audio_t, inline_query_result_contact_t, inline_query_result_game_t, inline_query_result_document_t, inline_query_result_gif_t, inline_query_result_location_t, inline_query_result_mpeg4_gif_t, inline_query_result_photo_t, inline_query_result_venue_t, inline_query_result_video_t, inline_query_result_voice_t>;

// This object represents the content of a media message to be sent. It should be one of
using input_media_t = variant_t<input_media_animation_t, input_media_document_t, input_media_audio_t, input_media_photo_t, input_media_video_t>;

// This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:
using input_message_content_t = variant_t<input_text_message_content_t, input_location_message_content_t, input_venue_message_content_t, input_contact_message_content_t, input_invoice_message_content_t>;

// This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:
using passport_element_error_t = variant_t<passport_element_error_data_field_t, passport_element_error_front_side_t, passport_element_error_reverse_side_t, passport_element_error_selfie_t, passport_element_error_file_t, passport_element_error_files_t, passport_element_error_translation_file_t, passport_element_error_translation_files_t, passport_element_error_unspecified_t>;
