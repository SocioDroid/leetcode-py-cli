import re
class Solution:
    def validIPAddress(self, IP: str) -> str:
        if '.' in IP:
            ls = [i for i in IP.split('.')]
            flag = False
            if len(ls) == 4:
                for i in range(len(ls)):                    
                    if len(ls[i])>1 and re.match('[0]{1}[0-9]{1,2}',ls[i]):
                        flag = False
                        break
                    try:
                        if re.match('[0-9]{1,3}',ls[i]):                        
                            if int(ls[i]) < 256 and int(ls[i]) >= 0:
                                flag = True
                            else:
                                flag = False
                                break
                        else:
                            flag = False
                            break
                    except:
                        return 'Neither'
            if flag:
                return 'IPv4'
            else:
                return 'Neither'
        elif ':' in IP:
            ls = IP.split(':')
            flag = False
            if len(ls) == 8:
                for i in ls:
                    if re.match(r'\b[0-9A-Fa-f]{1,4}\b',i):
                        flag = True
                    else:
                        flag = False
                        break
            if flag:
                return 'IPv6'
            else:
                return 'Neither'
        else:
            return 'Neither'
         