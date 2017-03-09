<?php

/**
 * @file
 * Views definitions for 'ding_redia_rss'.
 */

/**
 * Implements hook_views_data().
 */
function ding_redia_rss_views_data() {
  $data = array();
  // Add Ding Redia RSS group.
  $data['ding_redia_rss']['table']['group'] = t('Ding Redia RSS');
  $data['ding_redia_rss']['table']['join'] = array(
    '#global' => array(),
  );

  // Add library id field.
  $data['ding_redia_rss']['ding_redia_rss_handler_library_id'] = array(
    'title' => t('Library ID'),
    'help' => t("Provides a node's library id."),
    'field' => array(
      'handler' => 'ding_redia_rss_handler_library_id',
    ),
  );

  // Add library title field.
  $data['ding_redia_rss']['ding_redia_rss_handler_library_title'] = array(
    'title' => t('Library Title'),
    'help' => t("Provides a node's library title."),
    'field' => array(
      'handler' => 'ding_redia_rss_handler_library_title',
    ),
  );

  return $data;
}
