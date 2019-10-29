import jQuery from 'jquery';

(($ => {

  const sublistItem = $('.nav-primary__sublist');
  const toggle = $('.nav-primary__toggle');

  // Hide sub items in small device sizes
  sublistItem.addClass('nav-primary__sublist--hidden');

  // Show nav children on click of toggle
  toggle.on('click', function () {
    $(this).siblings('.nav-primary__sublist').toggleClass('nav-primary__sublist--hidden');
    $(this).toggleClass('is-open');
  });

}))(jQuery);
