KEY = /Users/iwoo/Desktop/nginx.key
CERT = /Users/iwoo/Desktop/nginx.crt

keys:
	# The CName used here is specific to the service specified in nginx-app.yaml.
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout $(KEY) -out $(CERT) -subj "/CN=nginxsvc/O=nginxsvc"

clean:
	rm $(KEY)
	rm $(CERT)