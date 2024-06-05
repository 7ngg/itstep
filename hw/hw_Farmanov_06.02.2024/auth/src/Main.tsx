import Button from "./Button";

function Main() {
  return (
    <div className="flex justify-between px-10 w-full h-dvh py-20">
      <Add />
      <List />
    </div>
  );
}

function Add() {
  return (
    <div className="h-3/5 w-2/5 grid bg-green-200 rounded-3xl shadow-2xl relative">
      <div className="p-3.5 flex flex-col gap-3 h-3/4">
        <div className="name">
          <h1 className="mb-1 text-sm font-bold">Name</h1>
          <input type="text" className="w-full p-3 shadow-md justify-self-center rounded-3xl resize-none" />
        </div>
        <div className="desc">
          <h1 className="mb-1 text-sm font-bold">Text</h1>
          <textarea className="w-full h-full p-3 shadow-md justify-self-center rounded-3xl resize-none"></textarea>
        </div>
      </div>
      <div className="w-1/3 flex justify-self-center absolute bottom-5">
        <Button text={"Click"} />
      </div>
    </div>
  );
}

function List() {
  return (
    <div className="h-3/5 w-2/5 grid text-center bg-green-200 rounded-3xl shadow-2xl relative">
      <div className="p-3.5 flex flex-col h-full">
        <h1 className="font-bold mb-3">List</h1>
        <div className="w-full h-full bg-white rounded-3xl"></div>
      </div>
    </div>
  );
}

export default Main;
