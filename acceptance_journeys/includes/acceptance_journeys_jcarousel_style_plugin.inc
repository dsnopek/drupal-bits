<?php

/**
 * @file
 * Contains the acceptance_journeys version of jCarousel style plugin.
 */

/**
 * Style plugin to render each item in an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class acceptance_journeys_jcarousel_style_plugin extends jcarousel_style_plugin {
  function option_definition() {
    $options = parent::option_definition();
    $options['columns'] = array('default' => '4');
    $options['alignment'] = array('default' => 'horizontal');
    $options['fill_single_line'] = array('default' => TRUE);
    $options['summary'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

       $form['rows'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of rows'),
      '#default_value' => $this->options['rows'],
      '#required' => TRUE,
      '#element_validate' => array('views_element_validate_integer'),
    );
        $form['fill_single_line'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fill up single line'),
      '#description' => t('If you disable this option, a grid with only one row will have the same number of table cells (<TD>) as items. Disabling it can cause problems with your CSS.'),
      '#default_value' => !empty($this->options['fill_single_line']),
    );
    
  }

}
