<?php

/**
 * Filter by queue name.
 */
class advancedqueue_handler_filter_queue_name extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Queue Name');

      // Populate the filter's options to include the entire queues list.
      $options = advancedqueue_get_queues_info();
      array_walk($options, function (&$value, $queue_machine_name) {
        $value = $value['label'];
      });
      $this->value_options = $options;
    }
  }
}
