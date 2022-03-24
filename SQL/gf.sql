drop database if exists ist181762;
create schema if not exists ist181762;
use ist181762;

-- create database gestor_frota;

set foreign_key_checks=0;

CREATE TABLE abastecimento
(
	id INTEGER NOT NULL,
	quilometragem INTEGER,
	a_data DATE,
	tipo VARCHAR(50),
	preco DOUBLE,
	litros DOUBLE,
	matricula VARCHAR(8),
	nome VARCHAR(255),
    primary key (id),
    key (matricula),
    key (nome)
)
;

CREATE TABLE atribuicao
(
	ano YEAR,
	matricula VARCHAR(8),
	id INTEGER,
    key (matricula),
    key (id)
)
;

CREATE TABLE colaborador
(
	id INTEGER NOT NULL,
	nome VARCHAR(255),
	cargo VARCHAR(50),
	departamento VARCHAR(50),
    dn DATE,
	contacto VARCHAR(50),
    primary key (id)
)
;

CREATE TABLE gasolineira
(
	marca VARCHAR(50) NOT NULL,
	desconto DOUBLE,
    primary key (marca)
)
;

CREATE TABLE posto
(
	nome varchar(255) NOT NULL,
	gps VARCHAR(255),
	marca VARCHAR(50),
    primary key (nome),
    key (marca)
)
;

CREATE TABLE viatura
(
	matricula VARCHAR(8) NOT NULL,
	cor VARCHAR(50),
	dm DATE,
	modelo VARCHAR(50),
	marca VARCHAR(50),
	motor VARCHAR(50),
	transmissao VARCHAR(50),
	combustivel VARCHAR(50),
	consumo_medio DOUBLE,
    primary key (matricula)
)
;
set foreign_key_checks=1;

alter table abastecimento add constraint FK_abastecimento_viatura
foreign key (matricula) references viatura (matricula);

alter table abastecimento add constraint FK_abastecimento_posto
foreign key (nome) references posto (nome);

alter table atribuicao add constraint FK_atribuicao_viatura
foreign key (matricula) references viatura (matricula);

alter table atribuicao add constraint FK_atribuicao_colaborador
foreign key (id) references colaborador (id);

alter table posto add constraint FK_posto_gasolineira
foreign key (marca) references gasolineira (marca);

set foreign_key_checks=0;
-- set global local_infile=1;




load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\colaborador.csv'
into table colaborador
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\viatura.csv'
into table viatura
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\posto.csv'
into table posto
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\gasolineira.csv'
into table gasolineira
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\abastecimento.csv'
into table abastecimento
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\BERNARDO LOPES\\iCloudDrive\\POBD\\SQL\\atribuicao.csv'
into table atribuicao
fields terminated by ';'
lines terminated by '\r\n';

set foreign_key_checks=1;


