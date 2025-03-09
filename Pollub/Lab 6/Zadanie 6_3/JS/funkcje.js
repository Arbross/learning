function funkcja() {
    var K = parseFloat(document.getElementById("kwotapozyczki").value);
    var pr = parseFloat(document.getElementById("oprocroczne").value);
    var n = parseFloat(document.getElementById("liczbarat").value);

    var pr_mc = document.getElementById("oprocroczniewskm");
    var wynik = document.getElementById("wynik");

    if (isNaN(K) || isNaN(pr) || isNaN(n)) {
        wynik.value = "Błędne dane";
        return;
    }

    var pr_mc_value = (pr / 12) / 100;
    pr_mc.value = (pr / 12).toFixed(2) + "%";

    if (!isFinite(pr_mc_value) || isNaN(pr_mc_value)) {
        wynik.value = "Błędne dane";
        return;
    }

    var rata = (K * pr_mc_value) / (1 - (1/(Math.pow((1 + pr_mc_value), n))));
    wynik.value = rata.toFixed(2) + " PLN";
}

function oblicz() {
    var tab = document.getElementsByName("operator");
    var op;

    for (let i = 0; i < tab.length; i++) {
        if (tab[i].checked) {
            op = tab[i].value;
        }
    }

    var x = parseFloat(document.getElementById("X").value);
    var y = parseFloat(document.getElementById("Y").value);

    var wynik = document.getElementById("wynik");

    if (isNaN(x) || isNaN(y)) {
        wynik.value = "Błędne dane";
        return;
    }

    switch (op) {
        case "+":
            wynik.value = x + y;
            break;
        case "-":
            wynik.value = x - y;
            break;
        case "*":
            wynik.value = x * y;
            break;
        case "/":
            var resultat = x / y;
            if (y == 0 || !isFinite(resultat)) {
                wynik.value = "Błędne dane";
                return;
            }

            wynik.value = resultat;
            break;
    
        default:
            wynik.value = "Błędne dane";
            break;
    }
} 
