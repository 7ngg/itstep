import { useParams } from "react-router-dom";

const Params = () => {
  const parameter = useParams<{ from: string; parameter: string }>();

  return (
    <div className="w-10/12 h-screen bg-gray-100 flex items-center justify-center">
      <h1>
        Parameter from {parameter.from}: {parameter.parameter}
      </h1>
    </div>
  );
};

export default Params;
