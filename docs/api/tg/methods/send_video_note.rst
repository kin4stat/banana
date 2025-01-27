.. _banana-api-tg-methods-send_video_note:

send_video_note
===============

.. cpp:namespace:: banana::api
.. cpp:function:: template <class Agent> \
                  api_result<message_t, Agent&&> send_video_note(Agent&& agent, send_video_note_args_t args)
.. cpp:function:: template <class Agent, class F> \
                  void send_video_note(Agent&& agent, send_video_note_args_t args, F&& callback)

   ``agent`` is any object satisfying :ref:`agent concept <banana-api-banana-agents>`.

   ``callback`` is any callable object accepting ``expected<message_t>``.

   As of v.4.0, Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent Message is returned.

.. cpp:struct:: send_video_note_args_t

   Arguments that should be passed to :cpp:func:`send_video_note`.


   .. cpp:member:: variant_t<integer_t, string_t> chat_id

   Unique identifier for the target chat or username of the target channel (in the format @channelusername)

   .. cpp:member:: optional_t<integer_t> message_thread_id

   Unique identifier for the target message thread (topic) of the forum; for forum supergroups only

   .. cpp:member:: variant_t<input_file_t, string_t> video_note

   Video note to send. Pass a file_id as String to send a video note that exists on the Telegram servers (recommended) or upload a new video using multipart/form-data. More information on Sending Files ». Sending video notes by a URL is currently unsupported

   .. cpp:member:: optional_t<integer_t> duration

   Duration of sent video in seconds

   .. cpp:member:: optional_t<integer_t> length

   Video width and height, i.e. diameter of the video message

   .. cpp:member:: optional_t<variant_t<input_file_t, string_t>> thumbnail

   Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail's width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can't be reused and can be only uploaded as a new file, so you can pass “attach://<file_attach_name>” if the thumbnail was uploaded using multipart/form-data under <file_attach_name>. More information on Sending Files »

   .. cpp:member:: optional_t<boolean_t> disable_notification

   Sends the message silently. Users will receive a notification with no sound.

   .. cpp:member:: optional_t<boolean_t> protect_content

   Protects the contents of the sent message from forwarding and saving

   .. cpp:member:: optional_t<reply_parameters_t> reply_parameters

   Description of the message to reply to

   .. cpp:member:: optional_t<variant_t<inline_keyboard_markup_t, reply_keyboard_markup_t, reply_keyboard_remove_t, force_reply_t>> reply_markup

   Additional interface options. A JSON-serialized object for an inline keyboard, custom reply keyboard, instructions to remove reply keyboard or to force a reply from the user.
