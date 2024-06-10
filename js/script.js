$(document).ready(function() {
    $('#burgerMenu').on('click', function() {
        $('#navLinks').toggleClass('active');
    });

    $('#servicesLink').on('click', function(e) {
        e.preventDefault();
        $('#servicesDropdown').toggleClass('active');
        $(this).find('.arrow-down').toggleClass('open');
    });
});
