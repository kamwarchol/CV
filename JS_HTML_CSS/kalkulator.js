        $("#submit").click(function() { 
          
          
        if($(".plus").hasClass("operation-active")){
            var firstValue = $('#first').val();
            var secondValue = $('#second').val();
        
          var wynik = parseFloat(firstValue) + parseFloat(secondValue);
          document.getElementById('result').innerHTML = wynik; 
          document.title = "Wynik to: " + wynik;
        }
        else if(  $(".minus").hasClass("operation-active")){
            var firstValue = $('#first').val();
            var secondValue = $('#second').val();
        
          var wynik = firstValue - secondValue; 
          document.getElementById('result').innerHTML = wynik;  
          document.title = "Wynik to: " + wynik;
        } 
        else  if(  $(".multi").hasClass("operation-active")){
            var firstValue = $('#first').val();
            var secondValue = $('#second').val();
        
          var wynik = firstValue * secondValue; 
          document.getElementById('result').innerHTML = wynik;
          document.title = "Wynik to: " + wynik;
        }
         else  if(  $(".division").hasClass("operation-active")){
            var firstValue = $('#first').val();
            var secondValue = $('#second').val();
        
          var wynik = firstValue / secondValue; 
          document.getElementById('result').innerHTML = wynik;  
          document.title = "Wynik to: " + wynik;
         }
        else  if(  $(".square").hasClass("operation-active")){
            var firstValue = $('#first').val();
           
          var wynik = firstValue * firstValue; 
          document.getElementById('result').innerHTML = wynik;  
          document.title = "Wynik to: " + wynik;
        }
          else  if(  $(".power").hasClass("operation-active")){
            var firstValue = $('#first').val();
            var secondValue = $('#second').val();
              
          var wynik = Math.pow(firstValue,secondValue); 
          document.getElementById('result').innerHTML = wynik;  
          document.title = "Wynik to: " + wynik;
          }
         else  if(  $(".root").hasClass("operation-active")){
            var firstValue = $('#first').val();
           
          var wynik = Math.sqrt(firstValue); 
          document.getElementById('result').innerHTML = wynik;  
          document.title = "Wynik to: " + wynik;
         }
        else {
            
             document.getElementById('result').innerHTML = "&#8681; Wybierz rodzaj operacji! &#8681;"; 
        }
    });  

