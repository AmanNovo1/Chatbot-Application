async function run() {
    const promt = document.getElementById('user-input');
    const result = await model.generateContent(prompt);
    const response = await result.response;
    const text = response.text();
    console.log(text);
    console.log(promt);
}

// async function sendMessage(){
//     const promt = document.getElementById('user-input');
//     const result = await model.generateContent(prompt);
//     const response = await result.response;
//     const text = response.text();
//     console.log(text);
// }