# Tigre Framework
Tigre is a modular framework to build web application using C++ without external depency. 

## Apache CGI
To configure Apache with CGI driver its simple, you just need to build the project with the `ApacheServiceProvider` and
configure the sites-enabled like this.

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
The NGINX FastCGI was not build yet.

## Road Map
The next features that going to be added soon is listed bellow, note that it's not in order.

- Database Connection Manager
- NGINX FastCGI Driver
- HTML Template Manager (Like Laravel Blade)
- FileSystem Driver
- MongoDB Driver
- Mysql/MariaDB Driver
- WebSocket Driver Manager
- Console Application System
