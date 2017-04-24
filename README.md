cd /home/ubuntu/CMT-Text-Detection

gunicorn -c gunicorn.config.py server.wsgi:app  --pid ./logs/gunicorn.pid --daemon
