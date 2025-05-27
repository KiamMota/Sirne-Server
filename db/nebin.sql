CREATE DATABASE IF NOT EXISTS nebin;
CREATE USER IF NOT EXISTS 'nebin'@'localhost' IDENTIFIED BY 'admin';
GRANT ALL PRIVILEGES ON nebin.* TO 'nebin'@'localhost';

FLUSH PRIVILEGES;

USE nebin;

CREATE TABLE dia(
    name VARCHAR(30) NOT NULL PRIMARY KEY
);

CREATE TABLE acompanhamento(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(60) NOT NULL,
    calories INT     NOT NULL,
    lactose  BOOLEAN NOT NULL,
    gluten   BOOLEAN NOT NULL
);

CREATE TABLE lanche(
    id INT NOT NULL  AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(60) NOT NULL,
    calories INT     NOT NULL,
    lactose BOOLEAN  NOT NULL,
    gluten BOOLEAN   NOT NULL
);

CREATE TABLE dia_lanche (
    dia_name VARCHAR(30)    NOT NULL,
    lanche_id INT           NOT NULL,
    PRIMARY KEY (dia_name, lanche_id),
    FOREIGN KEY (dia_name)  REFERENCES dia(name),
    FOREIGN KEY (lanche_id) REFERENCES lanche(id)
);

CREATE TABLE lanche_acompanhamento(
    lanche_id INT NOT NULL,
    acomp_id  INT NOT NULL,
    PRIMARY KEY (lanche_id, acomp_id),
    FOREIGN KEY (lanche_id) REFERENCES lanche(id),
    FOREIGN KEY (acomp_id)  REFERENCES acompanhamento(id)  
);
