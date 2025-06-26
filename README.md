# PartZone

Stranica za narucivanje auto dijelova

## Opis

PartZone je stranica za naručivanje auto dijelova. 
Projekt se sastoji od tablica s automobilima, dijelovima, slikama dijelova te narudžbama.
Omogućava pretraživanje baze auto dijelova odabirom automobila iz drop down liste te njihovo naručivanje. 
Postoji mogućnost registracije i prijave ili naručivanja kao guest korisnik.
Također je moguće dodavati i izmjenjivati podatke o automobilima i dijelovima ako se prijavio kao admin korisnik.

## Popis funkcionalnosti

Napravljene funkcionalnosti su **bold**

Smislenost objektnog modela - 11 bodova	\
**Da li objekti imaju smisla (minimalno 4 entity framework klase, ne racunajuci User)**\
**Da li tipovi podataka u objektima imaju smisla (datumi, nullable gdje treba, int vs string, ..)**\
**Da li su naznačene ispravne veze među objektima (1-N, N-N, nasljeđivanje)**
	

MVC Routing i URL prostori - 3 bodova\
Da li postoji kompletni izbornik u aplikaciji?\
Postoji li custom ruta definirana u RouteConfig-u? (recimo, /kompanije/pregled i sl.)\
Da li postoji ruta definirana atributima/anotacijama?
	

CRUD operacije i osnovni koncepti rukovanja entitetima - 24 bodova\
**Da li je kroz aplikaciju moguće izmjeniti podatke za barem 2 entiteta (ovisno o poslovnim pravilima)**\
Postoji li zajednicki partial view na edit+create formi?\
**Postoji li forma za pretraživanje koja koristi AJAX za dohvat rezultata?**\
**Postoji li validacija (server side)**\
Postoji li validacija (client side)\
**Drop down liste (unos vezanih vrijednosti obvezno preko drop down liste)**\
Postoji li seed za unos nekih inicijalnih vrijednosti (primjerice, gradovi i slično)\
**Jesu li ispravno implementirane migracijske skripte (postoji li initial i bar jos jedna migracija)**\
**Postoje li barem 3 elementa na sučelju implementirani pomoću Tag Helper-a?**\
Postoji li datumska kontrola i funkcionira li na barem 2 jezika s različitim formatom datuma?\
**Je li korisničko sučelje napravljeno slijeđenjem osnovnih bootstrap principa?**\
Postoji li "delete" implementiran pomoću AJAX poziva?
	

Organizacija aplikacije - 7 bodova\
**Postoji li DAL i model sloj?**\
**Jesu li ispravni elementi u svakom sloju?**
	

Autorizacija i autentikacija - 8 bodova\
Da li je implementiran Owin model?\
**Postoje li odvojene role za neke dijelove aplikacije?**\
Da li je Owin model ukombiniran sa vlastitom bazom?\
Da li je moguće registrirati korisnika (obično + jedan od servisa kao što je google ili FB)?
	

Web API - 7 bodova\
Postoji li mogućnost dohvata barem jednog tipa entiteta putem API-ja? (lista, preko id-a)\
Postoji li mogućnost dodavanja, izmjene i brisanja barem jednog entiteta putem API-ja?\
Opcionalno: Xamarin (isključivo!) aplikacija za prikaz jednog tipa podatka
	

Deployment i automatizacija - 15 bodova (dodatni - opcionalno)\
Ranija predaja - 6.6.\
Open AI integracija - ubacivanje chat-like opcije za pretragu ili nesto slicno\
Opcija 1: Kreirati samostalno Azure trial account i postaviti aplikaciju\
Opcija 2: Koristiti vlastitu virtualku / alternativni provider\
Opcija 3: Lokalni IIS server
