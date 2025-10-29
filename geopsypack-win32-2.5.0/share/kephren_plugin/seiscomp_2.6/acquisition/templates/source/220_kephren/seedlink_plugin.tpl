* template: #template#
plugin kephren cmd="#pkgroot#/bin/kephren_plugin -n $(uname -n) -server $(route | grep eth0 | grep default | awk '{print $2}')"
             timeout = 1200
             start_retry = 60
             shutdown_wait = 10

