document.getElementById('length').addEventListener('input', function() {
    var length = this.value;
    document.getElementById('lengthValue').innerText = length; // Update the length display dynamically
});

document.getElementById('passwordForm').addEventListener('submit', function(event) {
    event.preventDefault();
    var length = parseInt(document.getElementById('length').value);
    var includeUppercase = document.getElementById('uppercase').checked;
    var includeLowercase = document.getElementById('lowercase').checked;
    var includeNumbers = document.getElementById('numbers').checked;
    var includeSymbols = document.getElementById('symbols').checked;
    
    var passwordInfo = generatePassword(length, includeUppercase, includeLowercase, includeNumbers, includeSymbols);
    
    document.getElementById('password').innerText = passwordInfo.password;
    document.getElementById('passwordStrength').innerText = passwordInfo.strength;
    document.getElementById('passwordCount').innerText = passwordInfo.count;
});

function generatePassword(length, includeUppercase, includeLowercase, includeNumbers, includeSymbols) {
    var uppercaseChars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    var lowercaseChars = 'abcdefghijklmnopqrstuvwxyz';
    var numberChars = '0123456789';
    var symbolChars = '!@#$%^&*()-_+=~`[]{}|:;"\'<>,.?/';

    var chars = '';
    if (includeUppercase) chars += uppercaseChars;
    if (includeLowercase) chars += lowercaseChars;
    if (includeNumbers) chars += numberChars;
    if (includeSymbols) chars += symbolChars;

    var password = '';
    for (var i = 0; i < length; i++) {
        var randomIndex = Math.floor(Math.random() * chars.length);
        password += chars[randomIndex];
    }

    var possiblePasswords = Math.pow(chars.length, length);
    var strength = '';
    if (length < 8) {
        strength = 'Weak';
    } else if (length < 12) {
        strength = 'Moderate';
    } else {
        strength = 'Strong';
    }

    var scientificNotation = possiblePasswords.toExponential();
    return {
        password: password,
        strength: 'Strength: ' + strength,
        count: 'This password is 1 out of ' + scientificNotation + ' possible passwords.'
    };
}

function copyPassword() {
    var passwordText = document.getElementById('password');
    var textarea = document.createElement('textarea');
    textarea.value = passwordText.innerText;
    document.body.appendChild(textarea);
    textarea.select();
    document.execCommand('copy');
    document.body.removeChild(textarea);
    alert('Password copied to clipboard');
}
