function sprawdzPole(pole_id, obiektRegex) {
  // sprawdza pole za podanym id i regex
  var obiektPole = document.getElementById(pole_id);
  if (!obiektRegex.test(obiektPole.value)) return false;
  else return true;
}

function sprawdz_radio(nazwa_radio) {
  // Funkcja sprawdza czy wybrano przycisk radio
  // z grupy przycisków o nazwie nazwa_radio
  var obiekt = document.getElementsByName(nazwa_radio);
  for (i = 0; i < obiekt.length; i++) {
    wybrany = obiekt[i].checked;
    if (wybrany) return true;
  }
  return false;
}

function sprawdz_box(box_id) {
  // Funkcja sprawdza czy przycisk typu checkbox
  // o identyfikatorze box_id jest zaznaczony
  var obiekt = document.getElementById(box_id);
  if (obiekt.checked) return true;
  else return false;
}

function jaki_box() {
  let array = [];
  document.querySelectorAll('input[type="checkbox"]:checked').forEach(element => {
    array.push(element.value);
  });
  
  return array.toString();
}

function sprawdz() {
  var ok = true;
  obiektNazw = /^[a-zA-Z]{2,20}$/; // wyrażenie regularne dla nazwiska
  obiektemail = /^([a-zA-Z0-9])+([.a-zA-Z0-9_-])*@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-]+)+/;
  obiektWiek = /^[1-9][0-9]{1,2}$/;
  // Sprawdzanie kolejnych pól formularza.
  // w przypadku błędu - pojawia się odpowiedni komunikat
  if (!sprawdzPole("nazw", obiektNazw)) {
    ok = false;
    document.getElementById("nazw_error").innerHTML = '<span style="color: red;">Wpisz poprawnie nazwisko!</span>';
  } else document.getElementById("nazw_error").innerHTML = "";

  if (!sprawdzPole("wiek", obiektWiek)) {
    ok = false;
    document.getElementById("wiek_error").innerHTML = '<span style="color: red;">Wpisz poprawnie wiek!</span>';
  } else document.getElementById("wiek_error").innerHTML = "";

  if (!sprawdzPole("email", obiektemail)) {
    ok = false;
    document.getElementById("email_error").innerHTML = '<span style="color: red;">Wpisz poprawnie email!</span>';
  } else document.getElementById("email_error").innerHTML = "";

  if (!(sprawdz_box("php") || sprawdz_box("c") || sprawdz_box("java"))) {
    ok = false;
    document.getElementById("produkt_error").innerHTML = '<span style="color: red;">Muszisz wybrać produkt!</span>';
  } else document.getElementById("produkt_error").innerHTML = "";

  if (!sprawdz_radio("zaplata")) {
    ok = false;
    document.getElementById("zaplata_error").innerHTML = '<span style="color: red;">Muszisz wkazać sposób płatoności!</span>';
  } else document.getElementById("zaplata_error").innerHTML = "";

  if (!ok) return false;

  let zaplataElem = document.querySelector('input[name="zaplata"]:checked');
  let dane = 'Dane z wypełnionego przez Ciebie formularza:' +
    'Nazwisko: ' + document.getElementById("nazw").value + "\n" + 
    'Wiek: ' + document.getElementById("wiek").value + "\n" + 
    'Kraj: ' + document.getElementById("kraj").value + "\n" + 
    'Email: ' + document.getElementById("email").value + "\n" + 
    'Wybrane produkty: ' + jaki_box() + "\n" + 
    'Sposób zapłaty: ' + (zaplataElem ? zaplataElem.value : "Nie wybrano");

  return confirm(dane);
}
