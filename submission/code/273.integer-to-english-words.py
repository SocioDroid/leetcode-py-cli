class Solution:   
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        units = [
            "",
            "One ",
            "Two ",
            "Three ",
            "Four ", 
            "Five ", 
            "Six ",
            "Seven ",
            "Eight ",
            "Nine "
        ]
        
        tens = [
            "",
            "",
            "Twenty ",
            "Thirty ",
            "Forty ",
            "Fifty ",
            "Sixty ",
            "Seventy ",
            "Eighty ",
            "Ninety "
        ]
        
        conv = [
            "",
            "Thousand ",
            "Million ",
            "Billion ",
        ]
        
        ones = [
            'Ten',
            'Eleven',
            'Twelve',
            'Thirteen',
            'Fourteen',
            'Fifteen',
            'Sixteen',
            'Seventeen',
            'Eighteen',
            'Nineteen',
        ]
        # if temp == 0:
                # return ""
        def calc(num):
            string = ""
            temp = num
            temp_str = str(temp)
            if len(temp_str) == 1:
                string += units[temp%10]
            elif len(temp_str) == 2:
                if(temp_str[0]) == '1':
                    string += ones[temp%10]
                else:
                    string += tens[int(temp_str[0])] + units[temp%10]
            elif len(str(temp)) == 3:               
                if(temp_str[1]) == '1':
                    string += units[int(temp_str[0])] + 'Hundred '+ ones[temp%10]
                else:
                    string += units[int(temp_str[0])] + 'Hundred '+ tens[int(temp_str[1])] + units[temp%10]
            return string
            
        ext_string = ""
        ext_counter = 0
        int_counter = 0
        
        while(num):
            if num%1000:
                ext_string =  calc(num%1000).strip()+ " "+ conv[ext_counter] + ext_string 
            num = num // 1000
            ext_counter += 1
            
        return ext_string.strip()
    