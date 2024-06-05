import React from "react";

interface IAuthProps {
  isRegistered: boolean;
}

const LoginForm: React.FC<IAuthProps> = (props: IAuthProps) => {
  return (
    <div className="container grid bg-green-200 text-black rounded-3xl w-[400px] h-[400px]">
      {getForm(props.isRegistered)}
    </div>
  );
}

function getForm(isRegistered: boolean) {
  if (isRegistered) {
    return (
      <div className="p-5 flex flex-col items-center">
        <h1 className="text-5xl m-10 pt-0">Log In</h1>
        <form className="inputs px-10 pb-10">
          <input type="text" placeholder="Username" className="w-full rounded-lg shadow-black mb-3 pl-2 h-10 text-xl shadow-sm" />
          <input type="password" placeholder="Password" className="w-full rounded-lg shadow-black mb-3 pl-2 h-10 text-xl shadow-sm" />
          <button type="submit" className="w-full bg-black text-white text-2xl py-1 h-10 rounded-lg shadow-sm mt-10">Log In</button>
        </form>
      </div>
    );
  }

  return (
    <div className="p-5 flex flex-col items-center">
      <h1 className="text-5xl m-10 pt-0">Register</h1>
      <form className="inputs px-10 pb-10">
        <input type="text" placeholder="Username" className="w-full rounded-lg shadow-black mb-3 pl-2 h-10 text-xl shadow-sm" />
        <input type="email" placeholder="Email" className="w-full rounded-lg shadow-black mb-3 pl-2 h-10 text-xl shadow-sm" />
        <input type="password" placeholder="Password" className="w-full rounded-lg shadow-black mb-3 pl-2 h-10 text-xl shadow-sm" />
        <button type="submit" className="w-full bg-black text-white text-2xl py-1 h-10 rounded-lg shadow-sm mt-10">Register</button>
      </form>
    </div>
  );
}

export default LoginForm;
