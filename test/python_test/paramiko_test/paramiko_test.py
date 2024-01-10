import paramiko



host='192.168.199.101'
port=22
username='renjie'
password='*****'

remote_file_path='/home/renjie/tmp.txt'
local_file_path='./tmp.txt'

ssh=paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(host,port,username,password)

sftp = ssh.open_sftp()  

with sftp.open(remote_file_path, 'rb+') as remote_file:  

    with open(local_file_path, 'wb+') as local_file:  

        local_file.write(remote_file.read())  

  

# 关闭SSH连接  

sftp.close()  

ssh.close()