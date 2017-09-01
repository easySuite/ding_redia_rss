<?php

/**
 * @file
 * Node's "place2book" custom field handler.
 */

/**
 * Class ding_redia_rss_handler_place2book.
 */
class ding_redia_rss_handler_booking_url extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
  }

  function render($data) {
    $node = $data->_field_data['nid']['entity'];

    // Processing new version of P2B.
    if (isset($node->field_place2book)) {
      $new_p2b = field_get_items('node', $node, 'field_place2book');
      $event_maker_id = $new_p2b[0]['event_maker_id'];
      $event_id = $new_p2b[0]['event_id'];
      try {
        $p2b = ding_place2book_instance();
        $event = $p2b->getEvent($event_maker_id, $event_id);

        if ($event->meta_data->sales_status == 'open') {
          $link = $event->links->sales_location;
        }
      }
      catch (Exception $e) {
        watchdog_exception('ding_place2book', $e);
      }
    }
    else {
      // Processing old version of P2B.
      $place2book_id = db_select('ding_place2book', 'dp2b')
        ->fields('dp2b', array('place2book_id'))
        ->condition('nid', $node->nid)
        ->execute()
        ->fetchField();

      if ($place2book_id) {
        $service_settings = variable_get('ding_place2book', array());

        // Get the library id for the event.
        $library_id = ding_place2book_get_library_nid($node);

        $api_key = place2book_get_api_key($library_id);
        if ($api_key == NULL) {
          return;
        }

        // Check cache for the URL.
        if ($cache = cache_get($place2book_id . '_' . $library_id, 'cache_place2book')) {
          return $cache->data;
        };

        // @todo: Move http requests to a shared function responsible for setting
        // the correct headers. These bits seem to be repeated often - even with
        // variation. This could also include error handling.
        $headers = array(
          'X-PLACE2BOOK-API-TOKEN' => $api_key,
          'X-PLACE2BOOK-EVENT-ID' => $place2book_id,
        );
        $options = array(
          'method' => 'GET',
          'headers' => $headers,
        );
        $p2b_result = drupal_http_request(
          $service_settings['service_url'] . '/available_tickets',
          $options
        );

        $link = $p2b_result->headers['location'];
      }
    }

    return $link;
  }

}
