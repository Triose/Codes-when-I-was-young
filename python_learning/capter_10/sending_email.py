
import smtplib
from email.mime.text import MIMEText

# 没成功 先存疑
mail_host = "smtp.163.com"
mail_user = "triose@163.com"
mail_pass = "INPUT YOUR PASSWORD"

sender = "triose@163.com"
receivers = ["triose.lcy@gmail.com"]

content = "This is the main content of testing email"
title = "This is the title of testing email"

message = MIMEText(content, 'plain', 'utf-8')
message['from'] = "{}".format(sender)
message['to'] = ",".join(receivers)
message['subject'] = title

try:
    smtpObj = smtplib.SMTP_SSL(mail_host, 465)  # 启用SSL发信, 端口一般是465
    smtpObj.login(mail_user, mail_pass)  # 登录验证
    smtpObj.sendmail(sender, receivers, message.as_string())  # 发送
    print("mail has been send successfully.")
except smtplib.SMTPException as e:
    print(e)




