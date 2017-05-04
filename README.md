cd /home/ubuntu/CMT-Text-Detection

gunicorn -c gunicorn.config.py server.wsgi:app  --pid ./logs/gunicorn.pid --daemon






## Ver 2
### Extract the number block


### Split the number


### Retrain