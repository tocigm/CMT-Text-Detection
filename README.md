cd /home/ubuntu/project/CracksDetection

gunicorn -c gunicorn.config.py server.wsgi:app  --pid ./logs/gunicorn.pid --daemon
