const Globe = () => {
  return (
    <div className="w-10/12 h-screen bg-gray-100 flex">
      <div>
        <img
          src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/77/Restaurante_The_Swan%2C_Londres%2C_Inglaterra%2C_2014-08-11%2C_DD_113.jpg/1200px-Restaurante_The_Swan%2C_Londres%2C_Inglaterra%2C_2014-08-11%2C_DD_113.jpg"
          className="max-w-xs m-2 rounded-lg shadow-lg transition-transform transform hover:scale-105 hover:shadow-xl"
          alt="img"
        />
      </div>
      <p className="mx-5 my-2">
        Shakespeare's Globe is a realistic true-to-history reconstruction of the
        Globe Theatre, an Elizabethan playhouse first built in 1599 for which
        William Shakespeare wrote his plays. Like the original, it is located on
        the south bank of the River Thames, in Southwark, London. The
        reconstruction was completed in 1997 and while concentrating on
        Shakespeare's work also hosts a variety of other theatrical productions.
        Part of the Globe's complex also hosts the Sam Wanamaker Playhouse for
        smaller, indoor productions, in a setting which also recalls the period.
      </p>
    </div>
  );
};

export default Globe;
