# Tigre Framework
Tigre is a modular framework to build web applications using C++ without external dependencies.

## First Step
 
    git clone https://github.com/TigreFramework/Framework
    cd Framework
    git submodule update --init --recursive
    
## Build

    mkdir build
    cd build
    cmake ..
    make
    ./index.TigreFramework
    
## Docker Compose

    docker-compose up

## Apache CGI
To configure Apache with CGI driver, build the project with the `ApacheServiceProvider` and
configure the sites-enabled like the example below:

    <VirtualHost *:80>
      ServerAdmin webmaster@localhost
      DocumentRoot /var/www/public/

      ErrorLog ${APACHE_LOG_DIR}/cpp-error.log
      CustomLog ${APACHE_LOG_DIR}/cpp-access.log combined

      Options +ExecCGI
      Options Indexes FollowSymLinks ExecCGI
      AddHandler cgi-script .TigreFramework
      DirectoryIndex index.TigreFramework


      <Directory "/var/www/public/">
               AllowOverride All
               Options +ExecCGI
               Options Indexes FollowSymLinks ExecCGI
               Require all granted
      </Directory>
    </VirtualHost>
    
## NGINX FastCGI
The NGINX FastCGI is not yet ready.

## Working Functionalities

- Apache CGI Driver
- Database Connection Manager
- SQLite Driver
- PostgreSQL Driver

## Road Map
The next features to be added soon are listed below, not in any particular order:

- AWS Lambda Driver
- NGINX FastCGI Driver
- HTML Template Manager (Like Laravel Blade)
- FileSystem Driver
- MongoDB Driver
- Mysql/MariaDB Driver
- WebSocket Driver Manager
- Console Application System
- Rust Lang Support
