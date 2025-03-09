$(document).ready(function() {
    // Inicjalizacja lightbox
    lightbox.option({
        'resizeDuration': 200,
        'wrapAround': true
    });

    // Obsługa pokazu slajdów
    let currentSlide = 0;
    const slides = $("#slideshow img");
    const totalSlides = slides.length;

    // Funkcja zmieniająca slide z animacją
    function showSlide(index) {
        const current = slides.eq(currentSlide);
        const next = slides.eq(index);

        // Kierunek animacji
        const direction = index > currentSlide ? "next" : "prev";
        
        // Ustaw pozycje startowe
        next.css({
            "transform": direction === "next" ? "translateX(100%)" : "translateX(-100%)",
            "z-index": 2
        });
        
        current.css("z-index", 1);
        
        // Aktywuj animację
        current.animate({ 
            transform: direction === "next" ? "translateX(-100%)" : "translateX(100%)"
        }, 600);
        
        next.animate({ 
            transform: "translateX(0)" 
        }, 600, function() {
            current.css("transform", ""); // Reset pozycji
        });

        // Aktualizuj przyciski
        $("#sl-btns button").removeClass("active");
        $("#sl-btns button").eq(index).addClass("active");
        
        currentSlide = index;
    }

    // Automatyczne przewijanie
    let slideInterval = setInterval(() => {
        let nextSlide = (currentSlide + 1) % totalSlides;
        showSlide(nextSlide);
    }, 5000);

    // Obsługa przycisków
    $("#sl-btns button").click(function() {
        clearInterval(slideInterval);
        const index = $(this).index();
        if (index !== currentSlide) showSlide(index);
    });

    // Inicjalizacja
    slides.not(".active").css("transform", "translateX(100%)");
    $("#sl-btns button").first().addClass("active");
});