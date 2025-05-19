CREATE DATABASE IF NOT EXISTS nebin;
CREATE USER IF NOT EXISTS 'nebin'@'localhost' IDENTIFIED BY 'neb';
GRANT ALL PRIVILEGES ON nebin.* TO 'nebin'@'localhost';

FLUSH PRIVILEGES;

USE nebin;

CREATE TABLE blog (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titulo                VARCHAR(80),
    subtitulo             VARCHAR(250),
    conteudo              VARCHAR(2500),
    heart_emoji       INT DEFAULT 0,
    crying_emoji      INT DEFAULT 0,
    surprised_emoji   INT DEFAULT 0,
    thumbs_up_emoji   INT DEFAULT 0,
    thumbs_down_emoji INT DEFAULT 0,
    angry_emoji       INT DEFAULT 0
);

