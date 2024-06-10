$(document).ready(function() {


    setTimeout(function() {
        $('#preloader').animate({
            opacity: 0,
            width: '100%',
            height: '100%',
            marginTop: '0', // половина нової висоти
            marginLeft: '0' // половина нової ширини
        }, 500, function() {
            $(this).remove(); // Видаляємо прелоадер після анімації
        });
    }, 500);











    $('#burgerMenu').on('click', function() {
        $('#navLinks').toggleClass('active');
    });

    $('#servicesLink').on('click', function(e) {
        e.preventDefault();
        $('#servicesDropdown').toggleClass('active');
        $(this).find('.arrow-down').toggleClass('open');
    });





    
    function checkScroll() {
        $('.services_block').each(function() {
            if ($(this).isInViewport()) {
                $(this).addClass('scrolled');
            } else {
                $(this).removeClass('scrolled');
            }
        });
    }

    $(window).on('scroll', checkScroll);
    checkScroll(); // Initial check on page load

    $.fn.isInViewport = function() {
        var elementTop = $(this).offset().top;
        var elementBottom = elementTop + $(this).outerHeight();
        var viewportTop = $(window).scrollTop();
        var viewportBottom = viewportTop + $(window).height();
        return elementBottom > viewportTop && elementTop < viewportBottom;
    };




    
});




$('.slickSlider').slick({

    slidesToShow: 3,
    dots: true,
    responsive: [
      {
        breakpoint: 768,
        settings: {
          arrows: false,
          centerMode: true,
          centerPadding: '40px',
          slidesToShow: 2
        }
      },
      {
        breakpoint: 480,
        settings: {
          arrows: false,
          centerMode: true,
          centerPadding: '40px',
          slidesToShow: 1
        }
      }
    ]
  });

