.. _banana-api-tg-types-input_media_video:

input_media_video_t
===================

.. cpp:struct:: banana::api::input_media_video_t

   Represents a video to be sent.

   .. cpp:member:: string_t type

   Type of the result, must be video

   .. cpp:member:: string_t media

   File to send. Pass a file_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://<file_attach_name>” to upload a new one using multipart/form-data under <file_attach_name> name. More information on Sending Files »

   .. cpp:member:: optional_t<variant_t<input_file_t, string_t>> thumbnail

   Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail's width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can't be reused and can be only uploaded as a new file, so you can pass “attach://<file_attach_name>” if the thumbnail was uploaded using multipart/form-data under <file_attach_name>. More information on Sending Files »

   .. cpp:member:: optional_t<string_t> caption

   Optional. Caption of the video to be sent, 0-1024 characters after entities parsing

   .. cpp:member:: optional_t<string_t> parse_mode

   Optional. Mode for parsing entities in the video caption. See formatting options for more details.

   .. cpp:member:: optional_t<array_t<message_entity_t>> caption_entities

   Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode

   .. cpp:member:: optional_t<integer_t> width

   Optional. Video width

   .. cpp:member:: optional_t<integer_t> height

   Optional. Video height

   .. cpp:member:: optional_t<integer_t> duration

   Optional. Video duration in seconds

   .. cpp:member:: optional_t<boolean_t> supports_streaming

   Optional. Pass True if the uploaded video is suitable for streaming

   .. cpp:member:: optional_t<boolean_t> has_spoiler

   Optional. Pass True if the video needs to be covered with a spoiler animation
