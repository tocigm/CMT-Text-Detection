cd /home/ubuntu/CMT-Text-Detection

gunicorn -c gunicorn.config.py server.wsgi:app  --pid ./logs/gunicorn.pid --daemon


g++ `pkg-config --cflags --libs opencv cairo` fake_data/wh.cpp -o a.out && ./a.out
