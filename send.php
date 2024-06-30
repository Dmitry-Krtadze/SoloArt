<!DOCTYPE html>
<html lang="uk">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Головна - Soul Art</title>
    
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100;0,300;0,400;0,500;0,700;0,900;1,100;1,300;1,400;1,500;1,700;1,900&display=swap" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Noto+Serif:ital,wght@0,100..900;1,100..900&family=Roboto:ital,wght@0,100;0,300;0,400;0,500;0,700;0,900;1,100;1,300;1,400;1,500;1,700;1,900&display=swap" rel="stylesheet">
    <script src="https://unpkg.com/counterup2@2.0.2/dist/index.js">	</script>
    <link rel="stylesheet" href="path/to/plyr.css" />



    <link rel="stylesheet" href="css/reset.css">
    <link rel="stylesheet" href="css/slick-theme.css">
    <link rel="stylesheet" href="css/slick.css">
    <link rel="stylesheet" href="sass/style.css">
</head>
<body>
    <section id="preloader">
        <l-jelly-triangle
        size="100"
        speed="1.75"
        color="#B7B597" 
      ></l-jelly-triangle>
    </section>


    <header>
        <nav>
            <div class="logo">
                <a href="index.html">Soul Art</a>
            </div>
            <div class="burger-menu" id="burgerMenu">
                <span></span>
                <span></span>   
                <span></span>
            </div>
            <ul class="nav-links" id="navLinks">
                <li><a href="index.html">Головна</a></li>
                <li class="dropdown">
                    <a href="#" id="servicesLink">Послуги <span class="arrow-down"></span></a>
                    <ul class="dropdown-content" id="servicesDropdown">
                        <li><a href="wall_painting.html">Розпис стін</a></li>
                        <li><a href="3d_visualization.html">3D візуалізація інтер’єрів</a></li>
                        <li><a href="custom_paintings.html">Картини на замовлення</a></li>
                        <li><a href="object_painting.html">Розпис предметів</a></li>
                    </ul>
                </li>
                <li><a href="contacts.html">Контакти</a></li>
                <li><a href="about_us.html">Про нас</a></li>
            </ul>
        </nav>
    </header>
    <main>
        
       

    <h1 style="width: 100%; 
        height: auto; 
        font-family: Intro; 
        font-size: 35px; 
        display: flex; 
        justify-content: center; 
        margin: 20% 0 20% 0; 
        text-align: center;
    ">Дякуємо, наш адміністратор зв'яжеться з вами найближчим часом!</h1>

    </main>
    <footer>
        <!-- Контакти, соц мережі -->
    </footer>



    
    <script src="https://code.jquery.com/jquery-3.7.1.min.js" integrity="sha256-/JqT3SQfawRcv/BIHPThkBvs0OEvtFFmqPF/lYI/Cxo=" crossorigin="anonymous"></script>
    <script src="js/slick.min.js"></script>
    <script type="module" src="https://cdn.jsdelivr.net/npm/ldrs/dist/auto/jellyTriangle.js"></script>


    <script src="https://cdn.plyr.io/3.7.8/plyr.polyfilled.js"></script>

    <script src="js/slick.js"></script>
    <script src="js/script.js"></script>
</body>
</html>



<?php

$botToken = '7383455266:AAEe6uf-ApRggswGU2zTgTBSu6kz85MxYv0';
$chatId = '-4230102863';

$name = $_GET['name'];
$phone = $_GET['phone'];
$workType = $_GET['workType'];
if ($name != "") {
    // Формуємо текст повідомлення
    $text = "З'явився новий клієнт !\n\nІм'я: $name\nНомер телефону: $phone\n Тип роботи: $workType\n" ;

    // Формуємо URL для відправки повідомлення
    $apiUrl = "https://api.telegram.org/bot$botToken/sendMessage?chat_id=$chatId&text=" . urlencode($text);

    // Відправляємо запит методом POST за допомогою cURL
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $apiUrl);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $result = curl_exec($ch);
    curl_close($ch);
}
?>














