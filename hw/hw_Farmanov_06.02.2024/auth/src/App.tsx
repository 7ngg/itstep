import React from 'react';
import LoginForm from './auth';
import Main from './Main';
import MainHeader from './MainHeader';

function App() {
  return (
    <div className="App">
      <LoginForm isRegistered={true}/>
      <MainHeader />
      <Main />
    </div>
  );
}

export default App;
