.. _banana-api-tg-methods-edit_message_media:

edit_message_media
==================

.. cpp:namespace:: banana::api
.. cpp:function:: template <class Agent> \
                  api_result<variant_t<message_t, boolean_t>, Agent&&> edit_message_media(Agent&& agent, edit_message_media_args_t args)
.. cpp:function:: template <class Agent, class F> \
                  void edit_message_media(Agent&& agent, edit_message_media_args_t args, F&& callback)

   ``agent`` is any object satisfying :ref:`agent concept <banana-api-banana-agents>`.

   ``callback`` is any callable object accepting ``expected<variant_t<message_t, boolean_t>>``.

   Use this method to edit animation, audio, document, photo, or video messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can't be uploaded; use a previously uploaded file via its file_id or specify a URL. On success, if the edited message is not an inline message, the edited Message is returned, otherwise True is returned.

.. cpp:struct:: edit_message_media_args_t

   Arguments that should be passed to :cpp:func:`edit_message_media`.


   .. cpp:member:: optional_t<variant_t<integer_t, string_t>> chat_id

   Required if inline_message_id is not specified. Unique identifier for the target chat or username of the target channel (in the format @channelusername)

   .. cpp:member:: optional_t<integer_t> message_id

   Required if inline_message_id is not specified. Identifier of the message to edit

   .. cpp:member:: optional_t<string_t> inline_message_id

   Required if chat_id and message_id are not specified. Identifier of the inline message

   .. cpp:member:: input_media_t media

   A JSON-serialized object for a new media content of the message

   .. cpp:member:: optional_t<inline_keyboard_markup_t> reply_markup

   A JSON-serialized object for a new inline keyboard.
