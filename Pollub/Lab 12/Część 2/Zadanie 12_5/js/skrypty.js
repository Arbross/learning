document.addEventListener("DOMContentLoaded", function () {
  var but1 = document.getElementById("b1");
  but1.addEventListener(
    "click",
    function () {
      fetch("http://localhost/testajax/dane/info.txt")
        .then((response) => {
          return response.text();
        })
        .then((dane) => {
          document.getElementById("s1").innerHTML = dane;
        });
    },
    false
  );

  var but2 = document.getElementById("b2");
  but2.addEventListener(
    "click",
    function () {
        fetch("http://localhost/testajax/dane/act.txt")
        .then((response) => {
          return response.text();
        })
        .then((dane) => {
          document.getElementById("s1").innerHTML = dane;
        });
    },
    false
  );
  
  var but2 = document.getElementById("b3");
  but2.addEventListener(
    "click",
    function () {
        fetch("http://localhost/testajax/dane/gal.txt")
        .then((response) => {
          return response.text();
        })
        .then((dane) => {
          document.getElementById("s1").innerHTML = dane;
        });
    },
    false
  );

  var but2 = document.getElementById("b4");
  but2.addEventListener(
    "click",
    function () {
        fetch("http://localhost/testajax/dane/form.txt")
        .then((response) => {
          return response.text();
        })
        .then((dane) => {
          document.getElementById("s1").innerHTML = dane;
        });
    },
    false
  );
});
