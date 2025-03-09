function pokaz(id) {
    var tresc = "";
    switch (id) {
        case 2:
            tresc += pokazGalerie();
            break;
        case 3:
            tresc += pokazPost();
            break;
        case 4:
            tresc += pokazKontakt();
            break;
        default:
          tresc += pokazO();
    }

    document.getElementById("blok").innerHTML = tresc;
}

function pokazO() {
    var tresc = "<h2><br>Pierwsze kroki</h2>";

    tresc +=
      "<p>W aplikacjach typu SPA (ang. Single Page Application) po przesłaniu pierwszego żądania, również dochodzi do odesłania początkowego dokumentu HTML do przeglądarki, jednak po zakończeniu inicjalizacji wszelkie działania użytkownika prowadzą tylko do wysłania żądań asynchronicznie (w tle za pomocą AJAX) Odpowiedziami na te żądania zwykle są tylko fragmenty kodu HTML (zamiast całych dokumentów), a niekiedy wyłącznie dane, które następnie są wstawiane/zamieniane w ramach istniejących elementów dokumentu HTML. Nigdy nie dochodzi do zamiany całego dokumentu HTML.</p>" +
      '<p class="srodek"><img src="images/baner.jpg" alt="Zdjęcie" /></p>' +
      "<article><h2>Wady SPA</h2><p>" +
      "Czas wytworzenia oraz nakład pracy włożony w stworzenie aplikacji jest większy, co wiąże ze sobą dodatkowe koszta, dlatego tworzenie małych stron jest nieopłacalne - efekt dla strony z jedną zakładką jest niezauważalny Pozycjonowanie stron wymaga większego nakładu pracy. Obecnie roboty indeksujące Google nie radzą sobie ze stronami tego typu, co wiąże się z koniecznością tworzenia rozwiązań przystosowanych dla robotów.</p></article>";
    
    return tresc;
}

function pokazGalerie() {
    var tresc = '<h2><br>Moja galeria</h2>';
    tresc += '<div class="galeria">';
    for(let i = 1; i <= 8; i++) {
        tresc += '<div class="slajd"> <img src="images/image ' + i + '.jpg" alt="Zdjęcie ' + i + '" /></div>';
    }

    return tresc + '</div>';
}

function pokazKontakt() {
    var tresc = '<h2><br>Kontakt</h2><div style="text-align: center;">';
    
    tresc += '<img style="max-width: 800px;" src="https://storage.googleapis.com/gweb-uniblog-publish-prod/images/google_maps_helpful_hero_1.width-1300.jpg" alt="Google Maps"/> <br> <br>'
          + '<label style="font-weight: bold;">E-mail: </label>admin.spa@spa.admin.com</p>'
          + '<p><label style="font-weight: bold;">Telefon 1: </label>123456789</p>'
          + '<p><label style="font-weight: bold;">Telefon 2: </label>987654321</p>'
          + '<p><label style="font-weight: bold;">Adres: </label>ul. Główna 5</p>';

    return tresc + "</div>";
}

function pokazPost() {
    tresc = '<h2><br>Dodaj post</h2>';
    tresc += '<article class="srodek" ><form action="mailto:s101746@pollub.pl" method="post" onsubmit="return pokazDane();">' +
            'Twój email: <br> <input type="email" name="email" id="email" required /> <br>' +
            'Nazwisko i imię: <br> <input type="text" name="fullname" id="fullname" required /> <br>' +
            'Telefon: <br> <input type="tel" name="phone" id="phone" required /> <br>' +
            'Zainteresowania: <br>' +
            '<input type="checkbox" id="sport" name="zainteresowania" value="Sport"/> Sport ' +
            '<input type="checkbox" id="muzyka" name="zainteresowania" value="Muzyka"/> Muzyka ' +
            '<input type="checkbox" id="film" name="zainteresowania" value="Film"/> Film ' +
            '<input type="checkbox" id="inne" name="zainteresowania" value="Inne"/> Inne <br>' +
            'Wiek: <br>' +
            '<input type="radio" name="wiek" value="mniej niz 10" required/> Mniej niz 10 ' +
            '<input type="radio" name="wiek" value="10-20" required/> 10-20 ' +
            '<input type="radio" name="wiek" value="31-40" required/> 31-40 ' +
            '<input type="radio" name="wiek" value="41-50" required/> 41-50 ' +
            '<input type="radio" name="wiek" value="więcej niz 50" required/> Więcej niz 50 <br>' +
            'Komentarz: <br> <textarea rows="3" cols="20" id="wiadomosc" name="wiadomosc" required></textarea>' +
            '<br> <input type="submit" name="wyslij" value="Wyślij" />' +
            '</form></article>';

    return tresc;
}

function pokazDane() {
    var dane = "Następujące dane zostaną wysłane:\n";
    dane += "Email: " + document.getElementById('email').value + "\n";
    dane += "Nazwisko i imię: " + document.getElementById('fullname').value + "\n";
    dane += "Telefon: " + document.getElementById('phone').value + "\n";
    
    let zainteresowania = Array.from(document.querySelectorAll('input[name="zainteresowania"]:checked'))
                               .map(checkbox => checkbox.value).join(", ");
    dane += "Zainteresowania: " + (zainteresowania || "Brak") + "\n";
    
    let wiek = document.querySelector('input[name="wiek"]:checked');
    dane += "Wiek: " + (wiek ? wiek.value : "Nie wybrano") + "\n";

    dane += "Wiadomość: " + document.getElementById('wiadomosc').value + "\n";
    
    if (confirm(dane)) return true;
    else return false;
}
