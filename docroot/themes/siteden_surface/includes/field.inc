<?php

/**
 * @file
 * Theme and preprocess functions for fields.
 */

/**
 * Implements hook_preprocess_field().
 */
function siteden_surface_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  $vm = $element['#view_mode'];
  $field_name = $element['#field_name'];

  // Add a tags class for term reference label field on an entity full display.
  if (_siteden_surface_is_full_taxonomy_term_label($element)) {
    $variables['field_items_class'] = 'tags';
    $variables['is_heading'] = true;
    $variables['margin_bottom'] = true;

    // Loop through each item since these are multi-item fields.
    foreach ($variables['items'] as $key => $item) {
      // Add the tag classes to the link and wrapper.
      $variables['items'][$key]['attributes']->setAttribute('class', 'tags');
      $variables['items'][$key]['content']['#options']['attributes']['class'] = 'tags__tag';
    }
  }

  // Customize fields in full view mode.
  if ($vm == 'full') {

    if ($field_name == 'field_sf_event_location') {
      $variables['items'][0]['attributes']->setAttribute('class', 'icon icon--location');
    }

    if ($field_name == 'field_sf_event_map_link') {
      $variables['items'][0]['attributes']->setAttribute('class', 'icon icon--map');
    }

    if ($field_name == 'field_sf_position_title') {
      $variables['items'][0]['attributes']->setAttribute('class', 'u-space-mb--flush heading--primary');
    }

    if ($field_name == 'field_sf_office_hours') {
      $variables['attributes']['class'] = 'u-space-mb';
    }

    if ($field_name == 'field_sf_unit') {
      $variables['items'][0]['attributes']->setAttribute('class', 'meta-info meta-info--accent u-space-mb');
    }

    if ($field_name == 'field_sf_files') {
      $variables['is_heading'] = true;
      $variables['margin_bottom'] = true;
      $variables['field_items_class'] = 'list--link-icon';
    }
  }

  // Style the gallery images on the Gallery bundle full vm
  if ($vm == 'full' && $field_name == 'field_sf_gallery_photos') {
    $variables['field_items_class'] = 'gallery';

    foreach ($variables['items'] as $key => $item) {
      // Add the tag classes to the link and wrapper.
      $variables['items'][$key]['attributes']->setAttribute('class', 'gallery__item');
    }
  }
}

/**
 * Implements hook_theme_suggestions_field_alter().
 */
function siteden_surface_theme_suggestions_field_alter(array &$suggestions, array $variables) {
  $element = $variables['element'];

  // Add a theme suggestion for the view mode display of a specific node type
  // field--node--field-name--full.html.twig.
  $suggestions[] = 'field__' . $element['#entity_type'] . '__' . $element['#field_name'] . '__' . $element['#view_mode'];
  // field--node--field-name--bundle--full.html.twig.
  $suggestions[] = 'field__' . $element['#entity_type'] . '__' . $element['#field_name'] . '__' . $element['#bundle'] . '__' . $element['#view_mode'];

  // Add a theme suggestion for term reference label field on an entity full
  // display.
  if (_siteden_surface_is_full_taxonomy_term_label($element)) {
    // field--node--taxonomy-term-label--full.html.twig.
    $suggestions[] = 'field__' . $element['#entity_type'] . '__taxonomy_term_label__full';
  }
}

/**
 * Check if field is a term reference label on an full entity display.
 *
 * @param array $element
 *   The entity field to check for a term reference.
 *
 * @return bool
 *   Return TRUE if the field is on a full entity display with a term reference.
 */
function _siteden_surface_is_full_taxonomy_term_label(array $element) {
  if ($element['#view_mode'] == 'full'
    && isset($element[0]['#options']['entity_type'])
    && $element[0]['#options']['entity_type'] == 'taxonomy_term'
    && $element['#formatter'] == 'entity_reference_label'
  ) {
    return TRUE;
  }

  return FALSE;
}
