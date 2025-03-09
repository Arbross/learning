function zapiszPare(e) {
    e.preventDefault();
    var rgb = document.getElementById("rgb").value;
    var nazwa = document.getElementById("nazwa").value;

    localStorage.setItem(nazwa, rgb);
}

function usunDane(e) {
    e.preventDefault();
    localStorage.clear();
}

function pokazDane(e) {
    e.preventDefault();

    var list = document.getElementById("list");

    list.innerHTML += '<div style="display: flex; flex-direction: column; width: 100%;">';
    for (let i = 0; i < localStorage.length; i++) {
        const key = localStorage.key(i);
        const value = localStorage.getItem(key);
        
        list.innerHTML += '<div style="background-color: #' + value + '">' + key + ', kod koloru: ' + value + '</div>';
    }
    list.innerHTML += '</div>';
}
