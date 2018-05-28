<?php

/**
 * @file
 * Handles the ingest of the video embed code.
 */

/**
 * Defines a textfield form for ingestubg the remote video.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 *
 * @return array
 *   The drupal form definition.
 */
function islandora_remote_video_upload_form(array $form, array &$form_state) {
  $upload_size = min((int) ini_get('post_max_size'), (int) ini_get('upload_max_filesize'));
  $extensions = array('ogg mp4 mov qt m4v avi mkv');
  return array(
    'remote_video_embed' => array(
      '#title' => t('Embed code'),
      '#type' => 'textarea',
      '#required' => TRUE,
      '#description' => t('Enter your video embed code.'),
    ),
  );
}

/**
 * Submit handler, adds uploaded file to the video object.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 */
function islandora_remote_video_upload_form_submit(array $form, array &$form_state) {
  $object = $form_state['islandora']['objects'][0];
  if (empty($object['OBJ'])) {
    $ds = $object->constructDatastream('OBJ', 'M');
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['OBJ'];
  }
  $path = $form_state['values']['remote_video_embed'];
  $ds->content = $path;
  $ds->label = 'Video Embed Code';
  $ds->mimetype = 'text/plain';
}
