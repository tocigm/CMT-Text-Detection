killall -9 gunicorn
gunicorn -c gunicorn.config.py server.wsgi:app --pid logs/gunicorn.pid --daemon
sudo nginx -s reload

