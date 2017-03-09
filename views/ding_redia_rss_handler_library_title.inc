<?php

/**
 * @file
 * Node's "Library title" custom field handler.
 */

/**
 * Class ding_redia_rss_handler_library_title.
 */
class ding_redia_rss_handler_library_title extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {
    $node = $data->_field_data['nid']['entity'];
    $library_target = field_get_items('node', $node, 'og_group_ref');
    $id = $library_target[0]['target_id'];

    $title = db_select('node', 'n')
      ->fields('n', array('title'))
      ->condition('nid', $id)
      ->execute()
      ->fetchField();

    return $title;
  }
}
