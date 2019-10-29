<?php

/**
 * @file
 * Theme and preprocess functions for node template.
 */

/**
* Implements hook_preprocess_node().
*/
function siteden_surface_preprocess_node(&$variables) {
  $node = $variables["node"];
  $type = $node->getType();
  $vm = $variables["view_mode"];

  // if this is an article node and the view mode is listing, don't show the submitted info
  if ($type == 'sf_article' && $vm == 'listing') {
    $variables["display_submitted"] = false;
  }

  // if this is the full view mode for event pass some variables into the template
  if ($type == 'sf_event') {
    // TODO The date formatting needs some more processing to handle start and end dates with the same day
    // Get date and time info
    $date_field = $node->get('field_sf_dates');
    $dates = $date_field->get(0);
    $start_date_timestamp = $dates->get('start_date')->getValue()->getTimestamp();
    $end_date_timestamp = $dates->get('end_date')->getValue()->getTimestamp();
    $start_date_short = \Drupal::service('date.formatter')->format($start_date_timestamp, 'custom', 'M j, Y');
    $end_date_short = \Drupal::service('date.formatter')->format($end_date_timestamp, 'custom', 'M j, Y');
    $start_time = \Drupal::service('date.formatter')->format($start_date_timestamp, 'custom', 'g:i A, n/d');
    $end_time = \Drupal::service('date.formatter')->format($end_date_timestamp, 'custom', 'g:i A, n/d');

    // provide date and time variables to template
    $variables['event_start_date'] = $start_date_short;
    $variables['event_end_date'] = ' - ' . $end_date_short;
    $variables['event_start_time'] = $start_time;
    $variables['event_end_time'] = ' to ' . $end_time;
  }
}
