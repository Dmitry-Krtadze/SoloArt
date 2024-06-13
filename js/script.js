
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










    


document.addEventListener('DOMContentLoaded', function() {
    // Створення Intersection Observer
    const callback = entries => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const block = entry.target;
                const counter = block.querySelector('.counter');
                const targetValue = counter.getAttribute('data-target');
                const circle = block.querySelector('.circle');

                circle.style.strokeDasharray = `0, 100`; 

                setTimeout(() => {
                    circle.style.transition = 'stroke-dasharray 2s ease';
                    circle.style.strokeDasharray = `${targetValue}, 100`;
                }, 100); 

                counterUp(counter, {
                    duration: 2000,
                    delay: 16,
                });

                block.classList.add('is-visible');
                observer.unobserve(block); // Зупинити спостереження за елементом після анімації
            }
        });
    };

    const observer = new IntersectionObserver(callback, { threshold: 0.5 });

    document.querySelectorAll('.progress-block').forEach(block => {
        observer.observe(block);
    });
});

// Функція для анімації чисел
function counterUp(el, options) {
    const duration = options.duration || 1000;
    const delay = options.delay || 16;
    const target = parseInt(el.getAttribute('data-target'), 10);
    let count = 0;
    const increment = target / (duration / delay);

    const updateCounter = () => {
        count += increment;
        if (count > target) {
            el.textContent = target;
        } else {
            el.textContent = Math.round(count);
            setTimeout(updateCounter, delay);
        }
    };

    updateCounter();







}


var popup = document.getElementById("popupForm");
var btn = document.getElementById("openPopup");
var span = document.getElementsByClassName("close")[0];

btn.onclick = function() {
    popup.style.display = "block";
}

span.onclick = function() {
    popup.style.display = "none";
}

window.onclick = function(event) {
    if (event.target == popup) {
        popup.style.display = "none";
    }
}

