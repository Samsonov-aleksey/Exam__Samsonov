-- Database: Photolife
Create table Medicine_new(
	id serial primary key,
	name TEXT,
	descripriom TEXT,
	effects TEXT);
Insert into Medicine_new(id,name,descripriom,effects)
	values ('1','Нурофен','Нурофен снижает температуру тела', 'К основным противопоказаниям относится личная непереносимость лекарственных веществ');
Insert into patient(id,fullname,gender,date_birth,address)
	values('2','Алисия Заднепрянская','жен','2002-03-01','ул Московских пионеров д 44 к 1');
	
-- DROP DATABASE IF EXISTS "Photolife";
	Create table Medicine2(
	id serial primary key,
	name TEXT,
	descripriom TEXT,
	effects TEXT);
	Create table authoriz(
	login TEXT,
	password TEXT,
	id serial primary key,
	fullname TEXT);
	Create table calls(
	id serial primary key,
	patient_name TEXT,
	doctor_name TEXT,
	date TEXT,
	address TEXT,
	symptoms TEXT,
	diagnosis TEXT,
	prescription TEXT,
	medicine_id TEXT);
	Create table patient(
	id serial primary key,
	fullname TEXT,
	gender TEXT,
	date_birth TEXT,
	address TEXT);
	Insert into Medicine(id,name,descripriom,effects)
	values ('1','Ингавирин','Ингавирин снижает вирусную опасность', 'К основыным противопоказаниям относится'),
			('2','Ношпа','Форма выпуска, упаковка и состав Ношпы','Со стороны нервной системы: редкие заболевания'),
			('3','Смекта','От рвоты','Головокружение');
  	Insert into authoriz(login,password,id,fullname)
	values ('Ivan', 'Qwerty123!','1','Иваныч'),
			('fedor', 'Asdfg123!','2','Феодосиф'),
			('Alicia', '123','3','Elyacat');
	Insert into patient(id,fullname,gender,date_birth,address)
	values('1','Игорь Шуруб','муж','2002-01-02','ул Московских пионеров д 44 к 1');
	Insert into calls(id,patient_name,doctor_name,date,address,symptoms,diagnosis,prescription,medicine_id)
	values ('1','Шуруб И.С.','Иванов Иван','2022-02-02','Ул Кукушкина д 69 к2','Головная боль, температура','Грипп','Соблюдать постельный режим','Ингавирин'),
			('2','Алексей Самсонов','Иванов Иван','2022-02-01','Ул Космонавтов д 43','Рвота','Отравление','Пить смекту','Смекта');
	
