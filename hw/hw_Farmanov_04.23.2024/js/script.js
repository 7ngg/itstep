const openChatBtn = document.getElementById('open-chat-btn');
const closeChatBtn = document.getElementById('close-btn');
const chatPopup = document.querySelector('.chat-popup');

openChatBtn.onclick = () => {
  chatPopup.style.display = 'block';
  openChatBtn.style.display = 'none';
};

closeChatBtn.onclick = () => {
  chatPopup.style.display = 'none';
  openChatBtn.style.display = 'block';
}
