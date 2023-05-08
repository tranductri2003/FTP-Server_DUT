import os
from ftplib import *
from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer
import socket
# Set up a dummy authorizer for managing 'virtual' users
authorizer = DummyAuthorizer()
# Define a new user having full r/w permissions
authorizer.add_user("phatpham", "1234", ".", perm="elradfmwM")
authorizer.add_user("tritran", "1234", ".", perm="elradfmwM")
authorizer.add_user("tuanle", "1234", ".", perm="elradfmwM")
# Instantiate FTP handler class
handler = FTPHandler
handler.authorizer = authorizer
# Define a customized banner (string returned when client connects)
handler.banner = "Welcome to my FTP server!"
# Specify a masquerade address and the passive ports range
handler.masquerade_address = "123.456.789.012"
handler.passive_ports = range(60000, 65535)
# Instantiate FTP server class and listen to incoming connections
address = ("0.0.0.0", 21)
server = FTPServer(address, handler)
hostname = socket.gethostname()
print(f"Server Name: {hostname}")
ip = socket.gethostbyname("DUCTRITRAN")
print(f"IP: {ip}")
server.serve_forever()
