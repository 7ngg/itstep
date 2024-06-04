import React from 'react';
import LoginForm from './auth';

function App() {
  return (
    <div className="App">
      <LoginForm isRegistered={true} />
    </div>
  );
}

export default App;
