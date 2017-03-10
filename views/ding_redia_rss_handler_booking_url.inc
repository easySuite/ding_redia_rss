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

  function query() {}

  function render($data) {
    $node = $data->_field_data['nid']['entity'];
    // As we have difference between place2book modules between revisions, we
    // have to check if fields are existing.
    $p2b_fields = array('field_place2book', 'field_place2book_tickets');
    foreach ($p2b_fields as $p2b_field) {
      $existing = field_get_items('node', $node, $p2b_field);
      if (!empty($existing)) {
        $place2book = $existing;
        continue;
      }
    }

    if (!empty($place2book)) {
      $event_maker_id = $place2book[0]['event_maker_id'];
      $event_id = $place2book[0]['event_id'];

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

    return $link;
  }

}
