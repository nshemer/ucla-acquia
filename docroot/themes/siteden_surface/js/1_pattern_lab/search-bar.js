import jQuery from 'jquery';

(($ => {

  const breakpoint = 1024;

  // Show and hide the search bar on click
  $('.search-bar__btn').on('click', function () {
    const $this = $(this);

    $this.parent().toggleClass('search-bar--open');
    $this.next('.search-bar__form').toggleClass('u-hidden');
  });

  // Evaluate search bar states on page load
  evalSearch($(window).width());

  // Run evaluation on page resize
  $(window).resize(function () {
    evalSearch($(window).width());
  });

  // Show and hide search bar elements above and below browser width 1024px
  function evalSearch(windowWidth) {

    if (windowWidth >= breakpoint) {
      $('.search-bar').removeClass('search-bar--open');
      $('.search-bar__form').addClass('u-hidden');
    }
    else {
      $('.search-bar__form').removeClass('u-hidden');
    }
  }
}))(jQuery);
