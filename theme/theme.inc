<?php

/**
 * @file
 * Theme hooks.
 */

/**
 * Implements hook_preprocess().
 */
function islandora_remote_video_preprocess_islandora_remote_video(array &$variables) {
  module_load_include('inc', 'islandora', 'includes/datastream');
  module_load_include('inc', 'islandora', 'includes/utilities');
  module_load_include('inc', 'islandora', 'includes/solution_packs');
  module_load_include('inc', 'islandora', 'includes/authtokens');
  module_load_include('inc', 'islandora', 'includes/metadata');
  drupal_add_js('misc/form.js');
  drupal_add_js('misc/collapse.js');
  $object = $variables['object'];
  $repository = $object->repository;
  // We should eventually remove the DC object and dc_array code as it only
  // exists to not break legacy implementations.

  $variables['islandora_object_label'] = $object->label;
  $variables['theme_hook_suggestions'][] = 'islandora_video__' . str_replace(':', '_', $object->id);
  $variables['parent_collections'] = islandora_get_parents_from_rels_ext($object);
  $variables['description'] = islandora_retrieve_description_markup($object);

  $viewer_dsid = 'OBJ';

  $video_params = array(
    'pid' => $object->id,
  );
  // Video player.
  if (isset($object[$viewer_dsid]) && islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $object[$viewer_dsid])) {
    $embedded_video = $object[$viewer_dsid]->content;
  } 

  $variables['islandora_content'] = '';
  if ($embedded_video) {
    $variables['islandora_content'] = $embedded_video;
  }
  else {
    $variables['islandora_content'] = NULL;
  } 
  return array('' => $embedded_video);
}
